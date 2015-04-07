#!/bin/bash

usage()
{
  echo -e "Usage \n  $0 {make|clean} [all|<project-name>]"
  echo "Options"
  echo "  all (default)     all projects: auth se hello hello-test)"
  echo "  <project-name>    specified project"
}

# check command 
if [ -z "$1" ] 
then
  usage
  exit  
fi

# switch to codebase
projs="auth se hello hello-test"

#workerdir=$(basename `pwd`)
#for proj in $projs
#do
#  if [ "$proj" == "$workerdir" ]; then
#    cd ..
#    codebase=$(pwd)
#    break
#  fi
#done

codebase=$(pwd)

echo "workspace: $codebase"


check_proj()
{
  if [ ! -d $codebase/$1 ]; then
    echo "Not existed: $codebase/$1"
    return 0
  fi
  return 1
}

pull()
{
  echo "======== updating $1 ========"

  check_proj $1
  if [ "$?" == "0" ]; then
    return
  fi

  cd $codebase/$1
  git pull
}

compile()
{
  echo "========== compiling $1 =========="

  check_proj $1
  if [ "$?" == "0" ]; then
    return
  fi

  # cmake
  cd $codebase/$1
  if [ -e "$codebase/$1/CMakeLists.txt" ]; then
    mkdir build
    cd build    
    cmake ..
  elif [ -e "$codebase/$1/src/CMakeLists.txt" ]; then
    mkdir build
    cd build
    cmake ../source
  else
    echo "Not found CMakeLists.txt"
    return 
  fi
  
  # make
  make
}

clean()
{
  echo "======== clean $1 ======="
  
  check_proj $1
  if [ "$?" == "0" ]; then
    return
  fi

  echo "rm -rf $codebase/$1/build/*"  
  cd $codebase/$1
  rm -rf build/*
}

# process
if [ -n "$2" -a "$2" != "all" ]; then
  projs="$2"
fi

case "$1" in
pull)
  for proj in $projs
  do
    pull $proj
  done
  ;;
make)
  for proj in $projs
  do
    compile $proj
  done
  ;;
clean)
  for proj in $projs
  do
    clean $proj
  done
  ;;
*)
  usage
  ;;
esac
