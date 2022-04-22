from ubuntu:20.04

RUN apt-get update
RUN apt-get -y install libboost-dev libboost-program-options-dev libgtest-dev
RUN apt-get -y install cmake
RUN apt-get -y install make
RUN apt-get -y install g++
RUN apt-get install -y python3-pip
RUN pip install flask
#RUN useradd -m -s /bin/bash tp2022user
#USER tp2022user
USER root
WORKDIR opt/techprog
COPY . opt/techprog
RUN mkdir build && cd build && cmake .. && make
ENTRYPOINT python3 app.py --host 0.0.0.0 --port 8898
EXPOSE 8898



