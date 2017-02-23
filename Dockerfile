FROM ericsage/grpcc

ADD . /root/app

WORKDIR /root/app

RUN cmake .
RUN make

CMD ["/root/app/nexus"]
