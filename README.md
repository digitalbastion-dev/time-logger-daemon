 ARCH LINUX
1) g++ systemd.cpp -o systemd
2) sudo cp time-logger.service /etc/systemd/system/
3) sudo systemctl daemon-reload
4) sudo systemctl enable time-logger --now

