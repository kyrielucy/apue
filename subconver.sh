 #!/bin/bash

pkg="subconverter"
pkg_tgz="${pkg}_linux64.tar.gz"
workdir=${HOME}/Public/code/subconver/
git_url=https://github.com/tindy2013/subconverter/releases/latest/download

[ -f ${pkg_tgz} ] && rm -f ${pkg_tgz}*

wget ${git_url}/${pkg_tgz} -O ${workdir}/${pkg_tgz} -q

if [ -e ${workdir}/${pkg_tgz} ]; then
    tar -xzf ${workdir}/${pkg_tgz} -C ${workdir}
    chmod +rx ${workdir}/${pkg}/${pkg}
fi
