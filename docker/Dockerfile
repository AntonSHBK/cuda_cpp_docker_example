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
