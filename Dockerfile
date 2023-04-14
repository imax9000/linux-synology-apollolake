FROM ubuntu AS extract
RUN apt update -y
RUN apt install -y wget xz-utils

WORKDIR /buildenv

RUN wget -O /tmp/toolchain.txz https://global.synologydownload.com/download/ToolChain/toolchain/7.1-42661/Intel%20x86%20Linux%204.4.180%20%28Apollolake%29/apollolake-gcc850_glibc226_i686-GPL.txz && \
  [ "$(sha512sum /tmp/toolchain.txz | cut -d ' ' -f 1)" = "4d0b35433223325c0b718a14cdc0e2df52d732e7b39a1c20caddc50d5a8aeee32fd5c0cf829099aa4f601bc0056bdeaebf3ce2d3c000e1c1e062a2d67f3d80a6" ] && \
  mkdir -p /buildenv/usr/local && tar xf /tmp/toolchain.txz -C /buildenv/usr/local && rm /tmp/toolchain.txz

RUN wget -O /tmp/base_env.txz https://global.synologydownload.com/download/ToolChain/toolkit/7.0/base/base_env-7.0.txz && \
  [ "$(sha512sum /tmp/base_env.txz | cut -d ' ' -f 1)" = "805b2d01a9dc2bee5f6a5293e9765d6b0a145310bdd515cc8def0325e0a5dce94ae8ed2561cd5f4701508477007545d7c255b0f7919ec420751db49768f324ae" ] && \
  tar xf /tmp/base_env.txz && rm /tmp/base_env.txz

RUN wget -O /tmp/env.txz https://global.synologydownload.com/download/ToolChain/toolkit/7.0/apollolake/ds.apollolake-7.0.env.txz && \
  [ "$(sha512sum /tmp/env.txz | cut -d ' ' -f 1)" = "f36679dd0d9d184bcb9e7f428a54528eafbd219ce2e5f36a2e3e2dc0ddaba141a86c744f506df330d2e6675ea6552be6a0cd6812303280031621aa612854f035" ] && \
  tar xf /tmp/env.txz && rm /tmp/env.txz

RUN wget -O /tmp/dev.txz https://global.synologydownload.com/download/ToolChain/toolkit/7.0/apollolake/ds.apollolake-7.0.dev.txz && \
  [ "$(sha512sum /tmp/dev.txz | cut -d ' ' -f 1)" = "4b38ba80368cc100f17eec86bad145381fad3d7c26d52fe6f6dc72072579b788aaa387f241a1984cfd9ee4a17ef4b7ae06d80145a2c9304c636f4b8299e269a3" ] && \
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
