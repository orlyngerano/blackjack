FROM alpine:3.17.0 AS build

RUN apk update && \
    apk add --no-cache \
    build-base=0.5-r3 \
    libstdc++=12.2.1_git20220924-r4 \
    cmake=3.24.4-r0

WORKDIR /blackjack

COPY blackjack/ ./blackjack/
COPY tests/ ./tests/
COPY CMakeLists.txt .  

WORKDIR /blackjack/build

RUN cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build .

FROM alpine:3.17.0

RUN apk update && \
    apk add --no-cache \
    libstdc++=12.2.1_git20220924-r4 

COPY --from=build \
    ./blackjack/build/BlackJackGame \
    ./app/    

ENTRYPOINT [ "/app/BlackJackGame" ]