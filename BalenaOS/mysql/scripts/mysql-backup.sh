#!/etc/bash
mysqldump -u root -pEvolveAdmin grafanadb > seedbank.sql
#sshpass -p replace with personal server for backing up mysql database
