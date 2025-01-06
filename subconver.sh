 #!/bin/bash

curdir=$(pwd)
if [ ${XDG_BIN_DIR} ]; then
    workdir=${XDG_BIN_DIR}
else
    workdir=${HOME}/.local/bin/
fi

pkg="subconverter"
pkg_tgz="${pkg}_linux64.tar.gz"
git_url=https://github.com/tindy2013/subconverter/releases/latest/download

# chang to work directory
[ -d $workdir ] || mkdir -p $workdir
cd $workdir

[ -f ${pkg_tgz} ] && rm -f ${pkg_tgz}*

wget ${git_url}/${pkg_tgz} -O ${workdir}/${pkg_tgz} -q

if [ -e ${workdir}/${pkg_tgz} ]; then
    tar -xzf ${workdir}/${pkg_tgz} -C ${workdir}
    chmod +rx ${workdir}/${pkg}/${pkg}
fi

[ -f ${pkg_tgz} ] && rm -f ${pkg_tgz}

cd $curdir
