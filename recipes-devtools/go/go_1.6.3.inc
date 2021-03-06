require go.inc

DEPENDS += "go-bootstrap-native bash-native"
DEPENDS_class-target += "virtual/${TARGET_PREFIX}gcc virtual/${TARGET_PREFIX}g++"

SSTATE_SCAN_CMD = "true"

SRC_URI = "${SRC_URI_PREFIX}/go${PV}.src.tar.gz"
SRC_URI[md5sum] = "bf3fce6ccaadd310159c9e874220e2a2"
SRC_URI[sha256sum] = "6326aeed5f86cf18f16d6dc831405614f855e2d416a91fd3fdc334f772345b00"

SRC_URI += "\
        file://Fix-ccache-compilation-issue.patch \
        file://fix-cross-compilation.patch \
        file://cc-args.patch \
        "

LIC_FILES_CHKSUM = "file://LICENSE;md5=591778525c869cdde0ab5a1bf283cd81"

# The regular go>=1.5 binary can cross-compile based on GOARCH/GOOS
PROVIDES_append_class-native = "go-cross"
