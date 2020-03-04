/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "pqPV3blockMeshReaderPanel.h"

// QT
#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>
#include <QLayout>
#include <QString>
#include <QPushButton>
#include <QtDebug>

// Paraview <-> QT UI
#include "pqAnimationScene.h"
#include "pqApplicationCore.h"
#include "pqPipelineRepresentation.h"
#include "pqServerManagerModel.h"
#include "pqView.h"

// Paraview Server Manager
#include "vtkSMDoubleVectorProperty.h"
#include "vtkSMIntVectorProperty.h"
#include "vtkSMProperty.h"
#include "vtkSMSourceProxy.h"


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

pqPV3blockMeshReaderPanel::pqPV3blockMeshReaderPanel
(
    pqProxy *proxy,
    QWidget *p
)
:
    pqAutoGeneratedObjectPanel(proxy, p)
{
    // create first sublayout (at top of the panel)
    QGridLayout *form = new QGridLayout();
    this->PanelLayout->addLayout(form, 0, 0, 1, -1);

    vtkSMProperty* prop = 0;
    // checkbox for showing point numbers
    if ((prop = this->proxy()->GetProperty("UiShowPointNumbers")) != 0)
    {
        prop->SetImmediateUpdate(true);

        ShowPointNumbers_ = new QCheckBox("Show Point Numbers");
        ShowPointNumbers_->setToolTip("Show point numbers in render window.");
        ShowPointNumbers_->setChecked
        (
            vtkSMIntVectorProperty::SafeDownCast(prop)->GetElement(0)
        );

        form->addWidget(ShowPointNumbers_);

        connect
        (
            ShowPointNumbers_,
            SIGNAL(stateChanged(int)),
            this,
            SLOT(ShowPointNumbersToggled())
        );
    }

}

// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

void pqPV3blockMeshReaderPanel::ShowPointNumbersToggled()
{
    vtkSMIntVectorProperty::SafeDownCast
    (
        this->proxy()->GetProperty("UiShowPointNumbers")
    )->SetElement(0, ShowPointNumbers_->isChecked());

    // update the active view
    if (this->view())
    {
        this->view()->render();
    }
    // OR: update all views
    // pqApplicationCore::instance()->render();
}


// ************************************************************************* //
