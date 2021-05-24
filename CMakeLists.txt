cmake_minimum_required(VERSION 3.19)
project(ExpozitiaDeArta)

set(CMAKE_CXX_STANDARD 20)

add_executable(ExpozitiaDeArta main.cpp Expozitie.h Exceptie.h Pictura.h Invitat.h RepoT.h ServicePictura.h ServiceInvitat.h TestsRepoTInvitat.h TestRepoTPictura.h TestsServicePictura.h UI.h TestsServiceInvitat.h)