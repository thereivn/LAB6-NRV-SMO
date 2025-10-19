#!/bin/bash

sed -i 's/\r//' ESP32_CAM_Thermal_Energy.mo  # Удаляет Windows line endings

docker build -t esp32-cam-model .

mkdir -p output
chmod 777 output  # Даем права на запись

# Запускаем контейнер с правильным монтированием
docker run -it --rm -v $(pwd)/output:/output esp32-cam-model