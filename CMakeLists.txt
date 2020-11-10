cmake_minimum_required(VERSION 3.17)
project(PacketManager C)

set(CMAKE_C_STANDARD 99)

add_executable(PacketManager src/main.c src/PCAP/pcapReader.c src/PCAP/pcapReader.h src/BIT/DefType.h src/PACKET/EHEther.h src/PACKET/EHEther.c src/PACKET/IPv4.h src/PACKET/IPv4.c src/BIT/BitFunction.h src/BIT/BitFunction.c src/PACKET/UDP.c src/PACKET/UDP.h)