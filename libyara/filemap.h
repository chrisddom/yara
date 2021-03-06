/*
Copyright (c) 2007. Victor M. Alvarez [plusvic@gmail.com].

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef YR_FILEMAP_H
#define YR_FILEMAP_H

#ifdef WIN32
#include <windows.h>
#define FILE_DESCRIPTOR         HANDLE
#else
#define FILE_DESCRIPTOR         int
#endif

#include <stdlib.h>
#include <stdint.h>


typedef struct _MAPPED_FILE
{
  FILE_DESCRIPTOR     file;
  size_t              size;
  uint8_t*            data;
  #ifdef WIN32
  HANDLE              mapping;
  #endif

} MAPPED_FILE;


int yr_filemap_map(
    const char* file_path,
    MAPPED_FILE* pmapped_file);

void yr_filemap_unmap(
    MAPPED_FILE* pmapped_file);

#endif

