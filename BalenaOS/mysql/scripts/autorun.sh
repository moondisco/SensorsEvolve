#!/etc/bash
#every Hr sends mysql data to personal data server
watch -n 3600 bash mysql-backup.sh
