FROM ubuntu:latest

WORKDIR /root

RUN apt-get update && apt-get install -y wget curl git build-essential autoconf libtool

RUN git clone -b $(curl -L http://grpc.io/release) https://github.com/grpc/grpc
RUN cd /root/grpc && git submodule update --init && make && make install
RUN cd /root/grpc/third_party/protobuf && make && make install && make clean

RUN apt-get update && apt-get install -y wget
RUN wget http://www.cmake.org/files/v3.6/cmake-3.6.2.tar.gz && tar -xvzf cmake-3.6.2.tar.gz
RUN cd /root/cmake-3.6.2 && ./configure && make && make install && make clean

WORKDIR /root


