FROM nvidia/cuda:12.3.1-base-ubuntu22.04

# Set work directory
RUN mkdir /app
RUN mkdir /app/build
WORKDIR /app

# Install dependences
RUN apt-get update && \
    apt-get upgrade && \
    apt-get install -y \
        build-essential \
        cmake \
        python3 \
        python3-pip \
        pybind11-dev
RUN apt update && apt clean && rm -rf /var/lib/apt/lists/*

# Python dependences
COPY requirements.txt .
RUN pip install --no-cache-dir --upgrade -r requirements.txt

COPY . .

# CMD ["whatever", "you", "want"]


# Stage 1: Builder/Compiler
FROM python:3.8-slim as builder
RUN apt update && \
    apt install --no-install-recommends -y build-essential gcc
COPY req.txt /req.txt

RUN pip install --no-cache-dir --user -r /req.txt

# Stage 2: Runtime
FROM nvidia/cuda:10.1-cudnn7-runtime

RUN apt update && \
    apt install --no-install-recommends -y build-essential software-properties-common && \
    add-apt-repository -y ppa:deadsnakes/ppa && \
    apt install --no-install-recommends -y python3.8 python3-distutils && \
    update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.6 1 && \
    update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.8 2 && \
    apt clean && rm -rf /var/lib/apt/lists/*

COPY --from=builder /root/.local/lib/python3.8/site-packages /usr/local/lib/python3.8/dist-packages

COPY ./src /src

CMD ['python3', '/src/app.py']

EXPOSE 8080