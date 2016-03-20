﻿/*
 * [The "BSD license"]
 *  Copyright (c) 2016 Mike Lischke
 *  Copyright (c) 2013 Terence Parr
 *  Copyright (c) 2013 Dan McLaughlin
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

#include "PredicateTransition.h"
#include "stringconverter.h"

using namespace org::antlr::v4::runtime::atn;

PredicateTransition::PredicateTransition(ATNState *target, int ruleIndex, int predIndex, bool isCtxDependent) : AbstractPredicateTransition(target), ruleIndex(ruleIndex), predIndex(predIndex), isCtxDependent(isCtxDependent) {
}

int PredicateTransition::getSerializationType() {
  return PREDICATE;
}

bool PredicateTransition::isEpsilon() {
  return true;
}

bool PredicateTransition::matches(int symbol, int minVocabSymbol, int maxVocabSymbol) {
  return false;
}

SemanticContext::Predicate *PredicateTransition::getPredicate() {
  // TODO: who is responsible for managing this memory?
  return new SemanticContext::Predicate(ruleIndex, predIndex, isCtxDependent);
}

std::wstring PredicateTransition::toString() {
  return std::wstring(L"pred_") + antlrcpp::StringConverterHelper::toString(ruleIndex) + std::wstring(L":") + antlrcpp::StringConverterHelper::toString(predIndex);
}
