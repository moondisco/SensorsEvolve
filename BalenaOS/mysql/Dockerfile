FROM arm64v8/mariadb:10.2.38

ARG MYSQL_ROOT_PASSWORD 
ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD

ENV MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}
ENV MYSQL_DATABASE=${MYSQL_DATABASE}
ENV MYSQL_USER=${MYSQL_USER}
ENV MYSQL_PASSWORD=${MYSQL_PASSWORD}

COPY /sql-scripts /docker-entrypoint-initdb.d
VOLUME /docker-entrypoint-initdb.d 

COPY /scripts /

COPY /ssh-key/known_hosts /root/.ssh/

RUN apt-get update && apt-get -y install openssh-client sshpass cron nano
