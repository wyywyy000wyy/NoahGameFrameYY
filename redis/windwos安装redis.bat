安装wsl2
wsl --set-default-version 2 
wsl --install --d ubuntu-20.04
wsl -l -v


运行安装好的ubuntu

安装redis
curl -fsSL https://packages.redis.io/gpg | sudo gpg --dearmor -o /usr/share/keyrings/redis-archive-keyring.gpg
echo "deb [signed-by=/usr/share/keyrings/redis-archive-keyring.gpg] https://packages.redis.io/deb $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/redis.list
sudo apt-get update
sudo apt-get install redis

开启redis
sudo service redis-server start

测试连接redis
redis-cli
ping
