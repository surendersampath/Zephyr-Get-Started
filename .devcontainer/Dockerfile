FROM ghcr.io/zephyrproject-rtos/ci:main

ARG WORKDIR 
ARG TARGET
ARG TOOLCHAIN

ARG ZEPHYR_VERSION
ARG ZSDK_VERSION

# user's home directory.
USER user

RUN sudo apt update 
RUN sudo apt upgrade -y
RUN sudo apt-get install -y qemu-system-x86
RUN sudo -E -- bash -c ' \
	/opt/toolchains/zephyr-sdk-${ZSDK_VERSION}/setup.sh -c && \
	chown -R user:user /home/user/.cmake \
	'

WORKDIR /${WORKDIR}

RUN west init
RUN west update
RUN python3 -m pip install -r zephyr/scripts/requirements.txt

# Set the locale
ENV PKG_CONFIG_PATH=/usr/lib/i386-linux-gnu/pkgconfig
ENV OVMF_FD_PATH=/usr/share/ovmf/OVMF.fd

ENV LC_ALL=C.UTF-8
ENV LANG=C.UTF-8
ENV XDG_CACHE_HOME=/${WORKDIR}/.cache
ENV ZEPHYR_TOOLCHAIN_VARIANT=zephyr
ENV ZEPHYR_SDK_INSTALL_DIR=/${WORKDIR}/zephyr-sdk
ENV ZEPHYR_BASE=/${WORKDIR}/zephyr
ENV PATH="${ZEPHYR_BASE}/scripts:${PATH}"

RUN source ${ZEPHYR_BASE}/zephyr-env.sh
