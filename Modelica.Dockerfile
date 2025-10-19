FROM ubuntu:jammy

# It's good practice to use ARG after FROM
ARG VERSION="latest" 

RUN export DEBIAN_FRONTEND="noninteractive" && \
    echo "VERSION: $VERSION" && \
    test ! -z "$VERSION" && \
    # Update and upgrade system packages
    apt-get update && \
    apt-get upgrade -qy && \
    apt-get dist-upgrade -qy && \
    # Install necessary tools
    apt-get install -qy gnupg wget ca-certificates apt-transport-https && \
    # Add OpenModelica repository (using the stable channel)
    echo "deb https://build.openmodelica.org/omc/builds/linux/releases/$VERSION/ `lsb_release -cs` release" > /etc/apt/sources.list.d/openmodelica.list && \
    # Download and add the key (note: apt-key is deprecated, but this still works as a temporary measure)
    wget https://build.openmodelica.org/apt/openmodelica.asc -O- | apt-key add - && \
    # Update again with the new repo and install packages
    apt-get update && \
    apt-get install --no-install-recommends -qy omc cmake && \
    # Clean up to reduce image size
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

COPY CoffeeCooling.mo /models/CoffeeCooling.mo
CMD ["omc", "/models/CoffeeCooling.mo", "-simulate=CoffeeCooling,stopTime=1000"]