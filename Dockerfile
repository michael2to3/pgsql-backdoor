FROM postgres:latest

RUN apt-get update && apt-get install -y \
    postgresql-server-dev-all \
    build-essential \
    gcc \
    make

COPY admin.cpp /src/
COPY admin.control /src/
COPY Makefile /src/
COPY admin--1.0.sql /src/

WORKDIR /src

RUN make && \
    make install

RUN cp /src/admin.control /usr/share/postgresql/16/extension/ && \
    cp /src/admin--1.0.sql /usr/share/postgresql/16/extension/
