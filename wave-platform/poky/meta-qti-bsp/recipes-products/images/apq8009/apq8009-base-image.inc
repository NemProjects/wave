# Rootfs creation.

DEPENDS_append += "lk"
IMAGE_INSTALL += "packagegroup-core-boot"
IMAGE_INSTALL += "${ROOTFS_PKGMANAGE_BOOTSTRAP}"
IMAGE_INSTALL += "${CORE_IMAGE_EXTRA_INSTALL}"

# The MSM Linux minimal boot image files.
#IMAGE_INSTALL += "alsa-intf"
IMAGE_INSTALL += "alsa-lib"
IMAGE_INSTALL += "alsa-utils"
IMAGE_INSTALL += "tinycompress"

# AUDIO HAL
IMAGE_INSTALL += "audiohal"
IMAGE_INSTALL += "encoders"
IMAGE_INSTALL += "media"

#IMAGE_INSTALL += "alx"
#IMAGE_INSTALL += "avahi-systemd"
#IMAGE_INSTALL += "avahi-daemon"
#IMAGE_INSTALL += "avahi-dnsconfd"
#IMAGE_INSTALL += "avahi-autoipd"
#IMAGE_INSTALL += "avahi-utils"
#IMAGE_INSTALL += "pimd"
IMAGE_INSTALL += "base-files"
IMAGE_INSTALL += "base-passwd"
IMAGE_INSTALL += "bluez5"
#IMAGE_INSTALL += "bridge-utils"
#IMAGE_INSTALL += "compat-wireless-ath6kl"
#IMAGE_INSTALL += "conntrack-tools"
#IMAGE_INSTALL += "data-ipa-cfg-mgr"
#IMAGE_INSTALL += "data-oss"
IMAGE_INSTALL += "dhcpcd"
IMAGE_INSTALL += "dnsmasq"
#IMAGE_INSTALL += "ddclient"
#IMAGE_INSTALL += "e2fsprogs-e2fsck"
#IMAGE_INSTALL += "e2fsprogs-mke2fs"
IMAGE_INSTALL += "ebtables"
IMAGE_INSTALL += "ethtool"
IMAGE_INSTALL += "native-frameworks"
DEPENDS += "gdb-cross-arm"
#IMAGE_INSTALL += "gdbserver"
IMAGE_INSTALL += "gdb"
IMAGE_INSTALL += "glib-2.0"
#IMAGE_INSTALL += "hostap-daemon-qcacld"
# FIXME - This has a conflict with the task-core-boot.  You'll probably want to specify
# bbappend-s to things there or come up with a new task set that involves this recipe's
# work.
#IMAGE_INSTALL += "initscripts-msm"
IMAGE_INSTALL += "init-audio"
IMAGE_INSTALL += "iproute2"
IMAGE_INSTALL += "init-mss"
IMAGE_INSTALL += "iptables"
#IMAGE_INSTALL += "iw"
#IMAGE_INSTALL += "jquery"
#IMAGE_INSTALL += "jquery-ui"
#IMAGE_INSTALL += "kernel-modules"
#IMAGE_INSTALL += "libcomerr"
#IMAGE_INSTALL += "libss"
#IMAGE_INSTALL += "libe2p"
#IMAGE_INSTALL += "libext2fs"
IMAGE_INSTALL += "libnl"
#IMAGE_INSTALL += "libavahi-common"
#IMAGE_INSTALL += "libavahi-core"
#IMAGE_INSTALL += "libavahi-client"
#IMAGE_INSTALL += "libavahi-glib"
IMAGE_INSTALL += "libcutils"
IMAGE_INSTALL += "liblog"
#IMAGE_INSTALL += "libstdc++"
IMAGE_INSTALL += "libxml2"
#IMAGE_INSTALL += "lighttpd"
#IMAGE_INSTALL += "loc-api"
#IMAGE_INSTALL += "minidlna"
#IMAGE_INSTALL += "mtd-utils-ubifs"
#IMAGE_INSTALL += "openssl"
#IMAGE_INSTALL += "powerapp"
#IMAGE_INSTALL += "powerapp-powerconfig"
#IMAGE_INSTALL += "powerapp-reboot"
#IMAGE_INSTALL += "powerapp-shutdown"
#IMAGE_INSTALL += "ppp"
#IMAGE_INSTALL += "perl"
#IMAGE_INSTALL += "qcacld-ll"
#IMAGE_INSTALL += "qrngd"
IMAGE_INSTALL += "reboot-daemon"
#IMAGE_INSTALL += "rtsp-alg"
IMAGE_INSTALL += "start-scripts-find-partitions"
IMAGE_INSTALL += "start-scripts-firmware-links"
IMAGE_INSTALL += "system-core-adbd"
IMAGE_INSTALL += "system-core-logd"
IMAGE_INSTALL += "system-core-leprop"
IMAGE_INSTALL += "system-core-usb"
IMAGE_INSTALL += "system-core-debuggerd"
IMAGE_INSTALL += "system-core-post-boot"
IMAGE_INSTALL += "system-conf"
IMAGE_INSTALL += "system-prop"
IMAGE_INSTALL += "tcpdump"
IMAGE_INSTALL += "wireless-tools"
#IMAGE_INSTALL += "wlan"
IMAGE_INSTALL += "wcnss"
IMAGE_INSTALL += "wlan-opensource"
IMAGE_INSTALL += "qcacld-utils"
IMAGE_INSTALL += "hostap-daemon-qcacld"
IMAGE_INSTALL += "wpa-supplicant-qcacld"
IMAGE_INSTALL += "bt-app"
IMAGE_INSTALL += "bt-property"
IMAGE_INSTALL += "fluoride"
IMAGE_INSTALL += "libbt-vendor"
IMAGE_INSTALL += "display-hal-linux"
IMAGE_INSTALL += "start-scripts-qci-daemon"
IMAGE_INSTALL += "i2c-tools"
IMAGE_INSTALL += "pulseaudio-server"
IMAGE_INSTALL += "json-c"
IMAGE_INSTALL += "ffmpeg"
IMAGE_INSTALL += "curl"
IMAGE_INSTALL += "tzdata"
IMAGE_INSTALL += "gdb"
IMAGE_INSTALL += "valgrind"
IMAGE_INSTALL += "gcc"
IMAGE_INSTALL += "iw"
IMAGE_INSTALL += "ntp"
IMAGE_INSTALL += "aemp"
IMAGE_INSTALL += "keydet"
IMAGE_INSTALL += "chargemode"

#IMAGE_INSTALL += "gstreamer1.0"
#IMAGE_INSTALL += "gstreamer1.0-plugins-base"
#IMAGE_INSTALL += "gstreamer1.0-plugins-good"
#IMAGE_INSTALL += "gstreamer1.0-rtsp-server"
#IMAGE_PREPROCESS_COMMAND += "echo ${MACHINE} >> ${IMAGE_ROOTFS}/target;"

# Below packages are open source packages that depend on proprietary packages

#QMI_DIR_PRESENT = "${@os.path.exists('${WORKSPACE}/qmi')}"
#IMAGE_INSTALL += "${@base_conditional('QMI_DIR_PRESENT', 'True', 'wpa-supplicant-qcacld', '', d)}"

#DATA_DIR_PRESENT = "${@os.path.exists('${WORKSPACE}/data')}"
#IMAGE_INSTALL += "${@base_conditional('DATA_DIR_PRESENT', 'True', 'miniupnpd', '', d)}"

# Below is to generate sparse ext4 system image (OE by default supports raw ext4 images)

do_makesystem() {

    make_ext4fs -s -l ${SYSTEM_SIZE_EXT4} ${DEPLOY_DIR_IMAGE}/${MACHINE}-sysfs.ext4 ${IMAGE_ROOTFS}
}
