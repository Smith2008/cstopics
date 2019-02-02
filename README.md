Visit our [page](https://cstopics.github.io/cstopics/)

## Instalation:

Install Jekyll:

``` bash
$ sudo apt-get install ruby-full build-essential zlib1g-dev
$ echo '# Install Ruby Gems to ~/gems' >> ~/.bashrc
$ echo 'export GEM_HOME="$HOME/gems"' >> ~/.bashrc
$ echo 'export PATH="$HOME/gems/bin:$PATH"' >> ~/.bashrc
$ source ~/.bashrc
$ gem install jekyll bundler
```

Clone de repository

``` bash 
$ git clone https://github.com/cstopics/cstopics
$ cd cstopics

```

Install necesary gems:

``` bash
$ source installAll.sh
```

## Editing steps:

Start server:
``` bash
$ source startServer.sh
```

Open *http://127.0.0.1:4000/cstopics/* in the web browser.

## After editing:

Pull and push:

``` bash
$ source push.sh
```
