#See help target below for documentation

ifeq ($(build_name),)
    _build_name := $(shell git symbolic-ref --short HEAD 2>/dev/null)-local
else
    _build_name := $(build_name)
endif

ifeq ($(_build_name),)
    $(error ERROR: Unable to auto-detect build name. Check out a branch or specify with "build_name=...")
endif

# remove special chars
override _build_name := $(shell echo $(_build_name) | tr -dc '[:alnum:] ._-')

BUILD_ROOT := build

# make doesn't handle spaces well... replace them with underscores in paths
BUILD_DIR := $(BUILD_ROOT)/build-$(shell echo $(_build_name) | sed -e 's/ /_/g')
STEAM_DIR := $(HOME)/.steam/root

ifeq ($(build_name),)
    DEPLOY_DIR := $(shell git describe --tags --always --exclude proton-sdk*)
else
    DEPLOY_DIR := $(_build_name)
endif

ifneq ($(module),)
    ifneq ($(findstring .,$(module)),)
		MODULE_SFX :=
	else
		MODULE_SFX := .dll
	endif
endif

ifneq ($(unstripped),)
    UNSTRIPPED := UNSTRIPPED_BUILD=1
    DEPLOY_DIR := $(DEPLOY_DIR)_unstripped
endif

CONFIGURE_CMD := ../../configure.sh \
	--build-name="$(_build_name)"

ifneq ($(protonsdk_version),)
CONFIGURE_CMD += --proton-sdk-image=registry.gitlab.steamos.cloud/proton/soldier/sdk:$(protonsdk_version)
else
protonsdk_version := $(shell grep '^arg_protonsdk_image=' configure.sh|xargs echo|cut -d: -f2)
endif

enable_ccache := 1
ifneq ($(enable_ccache),0)
    CCACHE_FLAG := ENABLE_CCACHE=1
    CONFIGURE_CMD += --enable-ccache
endif

all: help

.PHONY: help clean configure proton install deploy module protonsdk

help:
	@echo "Proton Makefile instructions"
	@echo ""
	@echo "\"Quick start\" Makefile targets:"
	@echo "  install - Install Proton into current user's Steam installation"
	@echo "  redist - Build a package suitable for manual installation or distribution"
	@echo "           to other users in $(BUILD_ROOT)/ named after the nearest git tag"
	@echo "  deploy - Build Steam deployment files into a directory in $(BUILD_ROOT)/ named"
	@echo "           after the nearest git tag"
	@echo "  clean - Delete the Proton build directory"
	@echo ""
	@echo "Configuration variables:"
	@echo "  build_name - The name of the build, will be displayed in Steam. Defaults to"
	@echo "               current proton.git branch name if available. A new build dir"
	@echo "               will be created for each build_name, so if you override this,"
	@echo "               remember to always set it!"
	@echo "               Current build name: $(_build_name)"
	@echo "  unstripped - Set to non-empty to avoid stripping installed library files."
	@echo "  enable_ccache - Enabled by default, set to 0 to disable ccache."
	@echo "  protonsdk_version - Version of the proton sdk image to use for building,"
	@echo "                      use protonsdk_version=local to build it locally."
	@echo ""
	@echo "Development targets:"
	@echo "  configure - Configure Proton build directory"
	@echo "  proton - Build Proton"
	@echo ""
	@echo "  The following targets are development targets only useful after building Proton."
	@echo "  module - Rebuild a single Wine module and copy into $(BUILD_ROOT)/<module>/."
	@echo "           Specify module variable: make module=kernel32 module"
	@echo "  dxvk - Rebuild DXVK and copy it into $(BUILD_ROOT)/."
	@echo "  lsteamclient - Rebuild the Steam client wrapper and copy it into $(BUILD_ROOT)/."
	@echo ""
	@echo "Examples:"
	@echo "  make install - Build Proton and install into this user's Steam installation,"
	@echo "      with the current Proton branch name as the tool's name."
	@echo ""
	@echo "  make redist - Build a Proton redistribution package in a tagged directory"
	@echo "      in $(BUILD_ROOT)/."
	@echo ""
	@echo "  make build_name=mytest install - Build Proton with the tool name \"mytest\" and"
	@echo "      install into this user's Steam installation."
	@echo ""
	@echo "  make build_name=mytest module=dsound module - Build only the dsound module"
	@echo "      in the \"mytest\" build directory and place it into $(BUILD_ROOT)/dsound/."

clean:
	rm -rf $(BUILD_DIR)

protonsdk:
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C proton/docker $(UNSTRIPPED) $(CCACHE_FLAG) PROTONSDK_VERSION=$(protonsdk_version) proton

configure: | $(BUILD_DIR)
	if [ ! -e $(BUILD_DIR)/Makefile ]; then \
		(cd $(BUILD_DIR) && $(CONFIGURE_CMD)); \
	fi

ifeq ($(protonsdk_version),local)
configure: protonsdk
endif

downloads: configure
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR) downloads

proton: downloads
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) dist && \
	echo "Proton built in VM. Use 'install' or 'deploy' targets to retrieve the build."

install-internal: | $(BUILD_ROOT)/compatibilitytools.d/$(_build_name)
install-internal: downloads
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) install

install: install-internal
	mkdir -p $(STEAM_DIR)/compatibilitytools.d/
	cp -Rf --no-dereference --preserve=mode,links $(BUILD_ROOT)/compatibilitytools.d/$(_build_name) $(STEAM_DIR)/compatibilitytools.d/
	echo "Proton installed to your local Steam installation"

redist: | $(BUILD_ROOT)/$(DEPLOY_DIR)
redist: downloads
	rm -rf $(BUILD_ROOT)/$(DEPLOY_DIR)/* && \
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) redist && \
	cp -Rf $(BUILD_DIR)/redist/* $(BUILD_ROOT)/$(DEPLOY_DIR) && \
	echo "Proton build available at $(BUILD_ROOT)/$(DEPLOY_DIR)"

deploy: | $(BUILD_ROOT)/$(DEPLOY_DIR)-deploy
deploy: downloads
	rm -rf $(BUILD_ROOT)/$(DEPLOY_DIR)-deploy/* && \
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) deploy && \
	cp -Rf $(BUILD_DIR)/deploy/* $(BUILD_ROOT)/$(DEPLOY_DIR)-deploy && \
	echo "Proton deployed to $(BUILD_ROOT)/$(DEPLOY_DIR)-deploy"

module: | $(BUILD_ROOT)/$(module)/lib/wine/i386-windows
module: | $(BUILD_ROOT)/$(module)/lib/wine/i386-unix
module: | $(BUILD_ROOT)/$(module)/lib64/wine/x86_64-windows
module: | $(BUILD_ROOT)/$(module)/lib64/wine/x86_64-unix
module: downloads
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) module=$(module) module && \
	cp -f $(BUILD_DIR)/obj-wine32/dlls/$(module)/$(module)$(MODULE_SFX)* $(BUILD_ROOT)/$(module)/lib/wine/i386-windows/ && \
	cp -f $(BUILD_DIR)/obj-wine64/dlls/$(module)/$(module)$(MODULE_SFX)* $(BUILD_ROOT)/$(module)/lib64/wine/x86_64-windows/ && \
	if [ -e $(BUILD_DIR)/obj-wine32/dlls/$(module)/$(module).so ]; then \
		cp -f $(BUILD_DIR)/obj-wine32/dlls/$(module)/$(module).so $(BUILD_ROOT)/$(module)/lib/wine/i386-unix/ && \
		cp -f $(BUILD_DIR)/obj-wine64/dlls/$(module)/$(module).so $(BUILD_ROOT)/$(module)/lib64/wine/x86_64-unix/; \
	fi

dxvk: | $(BUILD_ROOT)/dxvk/lib/wine/dxvk
dxvk: | $(BUILD_ROOT)/dxvk/lib64/wine/dxvk
dxvk: downloads
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) dxvk && \
	cp -f $(BUILD_DIR)/dist/dist/lib/wine/dxvk/*.dll $(BUILD_ROOT)/dxvk/lib/wine/dxvk/ && \
	cp -f $(BUILD_DIR)/dist/dist/lib64/wine/dxvk/*.dll $(BUILD_ROOT)/dxvk/lib64/wine/dxvk/

dxvk-nvapi: | $(BUILD_ROOT)/dxvk-nvapi/lib/wine/nvapi
dxvk-nvapi: | $(BUILD_ROOT)/dxvk-nvapi/lib64/wine/nvapi
dxvk-nvapi: downloads
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) dxvk-nvapi && \
	cp -f $(BUILD_DIR)/dist/files/lib/wine/nvapi/*.dll $(BUILD_ROOT)/dxvk-nvapi/lib/wine/nvapi/ && \
	cp -f $(BUILD_DIR)/dist/files/lib64/wine/nvapi/*.dll $(BUILD_ROOT)/dxvk-nvapi/lib64/wine/nvapi/

vkd3d-proton: | $(BUILD_ROOT)/vkd3d-proton/lib/wine/vkd3d-proton
vkd3d-proton: | $(BUILD_ROOT)/vkd3d-proton/lib64/wine/vkd3d-proton
vkd3d-proton: downloads
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) vkd3d-proton && \
	cp -f $(BUILD_DIR)/dist/dist/lib/wine/vkd3d-proton/*.dll $(BUILD_ROOT)/vkd3d-proton/lib/wine/vkd3d-proton/ && \
	cp -f $(BUILD_DIR)/dist/dist/lib64/wine/vkd3d-proton/*.dll $(BUILD_ROOT)/vkd3d-proton/lib64/wine/vkd3d-proton/

lsteamclient: | $(BUILD_ROOT)/lsteamclient/lib/wine
lsteamclient: | $(BUILD_ROOT)/lsteamclient/lib64/wine
lsteamclient: downloads
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) lsteamclient && \
	cp -f $(BUILD_DIR)/dist/dist/lib/wine/lsteamclient.dll.so $(BUILD_ROOT)/lsteamclient/lib/wine && \
	cp -f $(BUILD_DIR)/dist/dist/lib64/wine/lsteamclient.dll.so $(BUILD_ROOT)/lsteamclient/lib64/wine

vrclient: | $(BUILD_ROOT)/vrclient/lib/wine
vrclient: | $(BUILD_ROOT)/vrclient/lib64/wine
vrclient: downloads
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) vrclient && \
	cp -f $(BUILD_DIR)/dist/dist/lib/wine/vrclient.dll.so $(BUILD_ROOT)/vrclient/lib/wine && \
	cp -f $(BUILD_DIR)/dist/dist/lib64/wine/vrclient_x64.dll.so $(BUILD_ROOT)/vrclient/lib64/wine

wineopenxr: | $(BUILD_ROOT)/wineopenxr/lib/wine
wineopenxr: | $(BUILD_ROOT)/wineopenxr/lib64/wine
wineopenxr: downloads
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) wineopenxr && \
	cp -f $(BUILD_DIR)/dist/dist/lib64/wine/wineopenxr.dll.so $(BUILD_ROOT)/wineopenxr/lib64/wine

battleye: | $(BUILD_ROOT)/battleye/v1/lib/wine
battleye: | $(BUILD_ROOT)/battleye/v1/lib64/wine
battleye: downloads
	$(MAKE) $(MFLAGS) $(MAKEOVERRIDES) -C $(BUILD_DIR)/ $(UNSTRIPPED) $(CCACHE_FLAG) battleye && \
	cp -f $(BUILD_DIR)/dist-battleye/v1/lib/wine/beclient.dll.so $(BUILD_ROOT)/battleye/v1/lib/wine && \
	cp -f $(BUILD_DIR)/dist-battleye/v1/lib64/wine/beclient_x64.dll.so $(BUILD_ROOT)/battleye/v1/lib64/wine

$(BUILD_ROOT)/%:
	mkdir -p $@
