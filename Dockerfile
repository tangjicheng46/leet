FROM ubuntu:20.04


ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    libboost-all-dev \
    curl 

WORKDIR /workspace

CMD ["bash"]
