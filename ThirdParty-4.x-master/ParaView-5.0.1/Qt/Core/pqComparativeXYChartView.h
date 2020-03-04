/*=========================================================================

   Program: ParaView
   Module:    $RCSfile$

   Copyright (c) 2005,2006 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2.

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

========================================================================*/
#ifndef pqComparativeXYChartView_h
#define pqComparativeXYChartView_h

#include "pqComparativeContextView.h"

/// The comparative line chart subclass.
class PQCORE_EXPORT pqComparativeXYChartView : public pqComparativeContextView
{
  Q_OBJECT
  typedef pqComparativeContextView Superclass;

public:
  pqComparativeXYChartView(const QString& group, const QString& name,
    vtkSMComparativeViewProxy* view, pqServer* server, QObject* parent=NULL);
  ~pqComparativeXYChartView();

  static QString chartViewType() { return "ComparativeXYChartView"; }
  static QString chartViewTypeName() { return "Line Chart View (Comparative)"; }

private:
  pqComparativeXYChartView(const pqComparativeXYChartView&); // Not implemented.
  void operator=(const pqComparativeXYChartView&); // Not implemented.
};

#endif
