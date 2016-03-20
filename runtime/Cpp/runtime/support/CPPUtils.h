/*
 * [The "BSD license"]
 *  Copyright (c) 2016 Mike Lischke
 *  Copyright (c) 2014 Dan McLaughlin
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

namespace antlrcpp {

  template<typename T1>
  class CopyOnWriteArrayList {
  public:
    CopyOnWriteArrayList(){};

  };

  std::wstring join(std::vector<std::wstring> strings, const std::wstring &separator);

  std::map<std::wstring, int>* toMap(const std::vector<std::wstring> &keys);

  std::wstring escapeWhitespace(std::wstring str, bool TODO);

  std::wstring stringFormat(const wchar_t* fmt, ...);

  wchar_t* toCharArray(const std::vector<size_t> *data);

  std::wstring toHexString(const int t);

  std::wstring arrayToString(const std::vector<std::wstring> &data);

  // Using RAII + a lambda to implement a "finally" relacement.
  template <typename F>
  struct FinalAction {
    FinalAction(F f) : _cleanUp { f } {}
    ~FinalAction() { if (_enabled) _cleanUp(); }
    void disable() { _enabled = false; };
  private:
    F _cleanUp;
    bool _enabled {true};
  };

  template <typename F>
  FinalAction<F> finally(F f) { return FinalAction<F>(f); }

} // namespace antlrcpp

