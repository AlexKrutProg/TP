from ubuntu:20.04

RUN apt-get update
RUN apt-get -y install cmake
RUN apt-get -y install make
RUN apt-get -y install g++
RUN apt-get -y intsall python3
RUN apt-get -y intsall python3-pip
RUN pip install flask
RUN useradd -m -s /bin/bash tp2022user
USER tp2022user
WORKDIR /home/tp2020user
COPY . /home/tp2020user
RUN mkdir build
RUN cd build
RUN cmake ..
RUN make
ENTRYPOINT python3 app.py --host 0.0.0.0 --port 8898
EXPOSE 8898



