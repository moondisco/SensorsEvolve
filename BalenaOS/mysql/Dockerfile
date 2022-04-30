FROM arm64v8/mariadb:10.2.38

ARG MYSQL_ROOT_PASSWORD 
ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD

ENV MYSQL_ROOT_PASSWORD=EvolveAdmin
ENV MYSQL_DATABASE=grafanadb
ENV MYSQL_USER=grafana
ENV MYSQL_PASSWORD=Evolve

COPY /sql-scripts /docker-entrypoint-initdb.d
VOLUME /docker-entrypoint-initdb.d 

RUN apt-get update && apt-get -y install openssh-client sshpass cron nano
