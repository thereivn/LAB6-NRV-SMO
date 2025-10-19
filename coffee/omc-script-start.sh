#!/bin/bash

sed -i 's/\r//' CoffeeCooling.mo  # Удаляет Windows line endings

docker build -t openmodelica-coffee .

mkdir -p output

docker run -it --rm -v $(pwd)/output:/app/output openmodelica-coffee