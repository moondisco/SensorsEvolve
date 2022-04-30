FROM grafana/grafana-oss:latest

ARG GF_PATHS_CONFIG=/etc/grafana/grafana.ini
ENV GF_PATHS_CONFIG=/etc/grafana/grafana.ini
COPY grafana.ini /etc/grafana/grafana.ini

COPY datasources.yaml /etc/grafana/provisioning/datasources/datasources.yaml

COPY home.json /etc/grafana/provisioning/dashboards/home.json
COPY home.json /usr/share/grafana/public/dashboards/home.json
