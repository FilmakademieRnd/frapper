/*
-----------------------------------------------------------------------------
This source file is part of FRAPPER
research.animationsinstitut.de
sourceforge.net/projects/frapper

Copyright (c) 2008-2016 Filmakademie Baden-Wuerttemberg, Institute of Animation 

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; version 2.1 of the License.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
-----------------------------------------------------------------------------
*/

//!
//! \file "CompositorTemplateNode.h"
//! \brief Header file for CompositorTemplateNode class.
//!
//! \author     Felix Bucella <felix.bucella@filmakademie.de>
//! \author     Nils Zweiling <nils.zweiling@filmakademie.de>
//! \author     Simon Spielmann <sspielma@filmakademie.de>
//! \version    1.2
//! \date       21.12.2012 (last updated)
//!

#ifndef COMPOSITORTEMPLATENODE_H
#define COMPOSITORTEMPLATENODE_H

#include "CompositorNode.h"
#include "InstanceCounterMacros.h"

namespace CompositorTemplateNode {
using namespace Frapper;

//!
//! Class implementing Screen Space Ambient Occlusion operations.
//!
class CompositorTemplateNode : public CompositorNode
{

    Q_OBJECT
    ADD_INSTANCE_COUNTER

public: // constructors and destructors

    //!
    //! Constructor of the CompositorTemplateNode class.
    //!
    //! \param name The name for the new node.
    //! \param parameterRoot A copy of the parameter tree specific for the type of the node.
    //!
    CompositorTemplateNode ( const QString &name, ParameterGroup *parameterRoot );

    //!
    //! Destructor of the CompositorTemplateNode class.
    //!
    //! Defined virtual to guarantee that the destructor of a derived class
    //! will be called if the instance of the derived class is saved in a
    //! variable of its parent class type.
    //!
    virtual ~CompositorTemplateNode ();


protected slots:
	
	////!
	////! Reload resources.
	////!
	void reload ();

protected: // functions

    //!
    //! Callback when instance of this class is registered as Ogre::CompositorListener.
    //! 
    //! \param pass_id Id to identifiy current compositor pass.
    //! \param mat Material this pass is currently using.
    //!
    virtual void notifyMaterialRender(Ogre::uint32 pass_id, Ogre::MaterialPtr &mat);

private slots:

    //!
    //! Processes the node's input data to generate the node's output image.
    //!
    void processOutputImage ();

	//!
	//! dd-- change preset values
	//!
	void renderPresetChanged();

	//!
	//! Changes the predefined values according to the index 
	//!
	void changePresetValue();
};

} // namespace CompositorTemplateNode
#endif