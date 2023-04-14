FROM ubuntu AS extract
RUN apt update -y
RUN apt install -y wget xz-utils

WORKDIR /buildenv

RUN wget -O /tmp/toolchain.txz https://global.synologydownload.com/download/ToolChain/toolchain/7.2-72746/Intel%20x86%20Linux%204.4.180%20%28Apollolake%29/apollolake-gcc1220_glibc236_x86_64-GPL.txz && \
  [ "$(sha512sum /tmp/toolchain.txz | cut -d ' ' -f 1)" = "801ed41e19d92047fc96bad46061b349f738b29b3d0eac8dc8c6f7f5217bce99a1de9015d1eb3c6d6949da228607ff179628cecd03dbc3108fe297a1380dbdbf" ] && \
  mkdir -p /buildenv/usr/local && tar xf /tmp/toolchain.txz -C /buildenv/usr/local && rm /tmp/toolchain.txz

RUN wget -O /tmp/base_env.txz https://global.synologydownload.com/download/ToolChain/toolkit/7.2/base/base_env-7.2.txz && \
  [ "$(sha512sum /tmp/base_env.txz | cut -d ' ' -f 1)" = "d8419cfb73e9f77cd551ab7b9e7ac9cccbea2ff62e718bf99b4395d326bf8646bb3d7aa5c77276c24c04e409cfa2b927d3aa131066dc053e87d95cc8c5dec817" ] && \
  tar xf /tmp/base_env.txz && rm /tmp/base_env.txz

RUN wget -O /tmp/env.txz https://global.synologydownload.com/download/ToolChain/toolkit/7.2/apollolake/ds.apollolake-7.2.env.txz && \
  [ "$(sha512sum /tmp/env.txz | cut -d ' ' -f 1)" = "4b35bb9fa7a81d33dc3f9eee4d49ee57e5d502a4ee109a5f924930d6af2c74ea3f351da343eb382d601508c17b33fa9810fbc6cc8a21a20b52d7a847c6e34044" ] && \
  tar xf /tmp/env.txz && rm /tmp/env.txz

RUN wget -O /tmp/dev.txz https://global.synologydownload.com/download/ToolChain/toolkit/7.2/apollolake/ds.apollolake-7.2.dev.txz && \
  [ "$(sha512sum /tmp/dev.txz | cut -d ' ' -f 1)" = "d7cd5aca9f3deb55d524ce515007ffc2cafab624d8336a2b23fe04a80646a0cd5008dfdb2fc1b0f73ff13105bf4a1bf3c767cef01664a319963a9f32ad43f72a" ] && \
  tar xf /tmp/dev.txz && rm /tmp/dev.txz

FROM ubuntu

RUN apt update -y
RUN apt upgrade -y && apt install -y build-essential openssl libssl-dev ncurses-dev python3 kmod bc

COPY --from=extract /buildenv /buildenv

ENV ARCH=x86_64
ENV CROSS_COMPILE="/buildenv/usr/local/x86_64-pc-linux-gnu/bin/x86_64-pc-linux-gnu-"

ENTRYPOINT ["make"]
VOLUME /src
WORKDIR /src
