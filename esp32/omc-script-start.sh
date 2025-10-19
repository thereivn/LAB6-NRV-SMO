#!/bin/bash

sed -i 's/\r//' ESP32_CAM_Thermal_Energy.mo  # Удаляет Windows line endings

docker build -t esp32-cam-model .

mkdir -p output

docker run -it --rm -v $(pwd)/output:/app/output esp32-cam-model