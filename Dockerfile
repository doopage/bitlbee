FROM alpine:latest

RUN apk add --no-cache --update \
	bash shadow build-base git python2 autoconf automake libtool mercurial intltool flex \
	glib-dev openssl-dev pidgin-dev json-glib-dev libgcrypt-dev zlib-dev libwebp-dev \
	libpng-dev protobuf-c-dev libxml2-dev discount-dev sqlite-dev http-parser-dev

RUN useradd bitlbee && \
  mkdir -p /var/lib/bitlbee && \
  chown bitlbee: /var/lib/bitlbee && \
  touch /var/run/bitlbeed.pid && \
  chown bitlbee: /var/run/bitlbeed.pid

ADD . /build/

WORKDIR /build
RUN ./configure --build=x86_64-alpine-linux-musl --host=x86_64-alpine-linux-musl --purple=1 --ssl=openssl --prefix=/usr --etcdir=/etc/bitlbee \
 && make \
 && make install \
 && make install-dev \
 && make install-etc \
 && strip /usr/sbin/bitlbee

USER bitlbee

CMD [ "/usr/sbin/bitlbee", "-F", "-n", "-u", "bitlbee", "-P", "/var/run/bitlbeed.pid" ]
