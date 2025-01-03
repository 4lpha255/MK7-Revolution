#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

export TOPDIR ?= $(CURDIR)
include $(DEVKITARM)/3ds_rules

HASH 		:= $(shell git rev-parse --short HEAD)

NAME 		:= RevolutionBase
ABOUT 		:= $(NAME) is a CTRPluginFramework plugin with some improvements.\n\nHash: HASH

CTRPFLIB	?=	$(DEVKITPRO)/libctrpf

TARGET		:= 	$(notdir $(CURDIR))
PLGINFO 	:= 	$(notdir $(TOPDIR)).plgInfo

INCLUDES	:= 	include \
				vendor/glaze/include
SOURCES 	:= 	src \
				src/base \
				src/base/entries/base \
				src/base/entries/debug \
				src/base/features \
				src/base/hook_types \
				src/base/hooks \
				src/base/memory \
				src/base/services

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
DEFINES 	:= -D__3DS__ \
				-DHASH="\"$(HASH)\"" -DNAME="\"$(NAME)\"" -DABOUT="\"$(ABOUT)\""

ARCH		:= -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS		:= $(ARCH) -Os -mword-relocations -fomit-frame-pointer -ffunction-sections -fno-strict-aliasing \
				-Wall -Wextra -Wno-psabi \
				$(BUILD_FLAGS) $(INCLUDE) $(DEFINES)

CXXFLAGS	:= $(CFLAGS) -fno-rtti -fno-exceptions -std=gnu++23

ASFLAGS		:= $(ARCH)
LDFLAGS		:= -T $(TOPDIR)/3gx.ld $(ARCH) -Os -fno-lto -Wl,--gc-sections,--strip-discarded,--strip-debug

LIBS		:= -lctrpf -lctru
LIBDIRS		:= $(CTRPFLIB) $(CTRULIB) $(PORTLIBS)

#---------------------------------------------------------------------------------
# no real need to edit anything past this point unless you need to add additional
# rules for different file extensions
#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))
#---------------------------------------------------------------------------------

export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
					$(foreach dir,$(DATA),$(CURDIR)/$(dir))

export DEPSDIR	:=	$(CURDIR)/$(BUILD)

CFILES			:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES			:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))

export LD 		:= 	$(CXX)
export OFILES	:=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I $(CURDIR)/$(dir) ) \
					$(foreach dir,$(LIBDIRS),-I $(dir)/include) \
					-I $(CURDIR)/$(BUILD)

export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L $(dir)/lib)

.PHONY: clean re all

#---------------------------------------------------------------------------------
all: release debug

release : release_dir
	@$(MAKE) BUILD=release OUTPUT=$(CURDIR)/$(TARGET)-release.3gx \
	DEPSDIR=$(CURDIR)/release \
	--no-print-directory --jobs=$(shell nproc) -C release -f $(CURDIR)/Makefile

debug : debug_dir
	@$(MAKE) BUILD=debug OUTPUT=$(CURDIR)/$(TARGET)-debug.3gx \
	DEPSDIR=$(CURDIR)/debug BUILD_CFLAGS="-D_DEBUG" \
	--no-print-directory --jobs=$(shell nproc) -C debug -f $(CURDIR)/Makefile

release_dir:
	@[ -d release ] || mkdir -p release

debug_dir:
	@[ -d debug ] || mkdir -p debug

#---------------------------------------------------------------------------------
clean:
	@echo clean ... 
	@rm -fr release debug *.3gx *.elf

re: clean all

#---------------------------------------------------------------------------------

else

#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------

DEPENDS	:=	$(OFILES:.o=.d)

$(OUTPUT) : $(basename $(OUTPUT)).elf
$(basename $(OUTPUT)).elf : $(OFILES)
#---------------------------------------------------------------------------------
# you need a rule like this for each extension you use as binary data
#---------------------------------------------------------------------------------
%.bin.o	:	%.bin
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#---------------------------------------------------------------------------------
%.3gx: %.elf
#---------------------------------------------------------------------------------
	@echo creating $(notdir $@)
	@3gxtool -d -s $^ $(TOPDIR)/$(PLGINFO) $@

-include $(DEPENDS)

#---------------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------------
