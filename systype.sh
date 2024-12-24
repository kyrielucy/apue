 #

# Determin the type of *ix operating system that we're
# running on, and echo an appropriate value.
#

case `uname -s` in
    "FreeBSD")
        PLATFORM="freebsd"
        ;;
    "Linux")
        PLATFORM="linux"
        ;;
    "Darwin")
        PLATFORM="macos"
        ;;
    "Sunos")
        PLATFORM="solaris"
        ;;
    *)
        echo "Unknown platfom" >&2
        exit 1
esac
echo $PLATFORM
exit 0
