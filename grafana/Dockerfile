FROM grafana/grafana-oss:latest

ARG GF_PATHS_CONFIG=/etc/grafana/grafana.ini
ENV GF_PATHS_CONFIG=/etc/grafana/grafana.ini

COPY grafana.ini /etc/grafana/grafana.ini
COPY home.json /usr/share/grafana/public/dashboards/home.json

ARG GF_PATHS_PROVISIONING=/etc/grafana/provisioning/
COPY datasources.yaml /usr/share/grafana/conf/provisioning/datasources/datasources.yaml
COPY datasources.yaml etc/grafana/provisioning/datasources/datasources.yaml

