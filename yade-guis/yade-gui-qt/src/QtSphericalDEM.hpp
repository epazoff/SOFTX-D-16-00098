/***************************************************************************
 *   Copyright (C) 2004 by Olivier Galizzi                                 *
 *   olivier.galizzi@imag.fr                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __QTSPHERICALDEMSIMULATOR_HPP__
#define __QTSPHERICALDEMSIMULATOR_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <qlayout.h>
#include <qframe.h>
#include <qscrollview.h>

#include <QtGeneratedSphericalDEMSimulator.h>

#include <boost/shared_ptr.hpp>

#include <yade/yade-lib-time/Chrono.hpp>

using namespace boost;

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <yade/yade-lib-factory/Factorable.hpp>
#include <yade/yade-core/StandAloneSimulator.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief 

	
*/
class QtSphericalDEM : public QtGeneratedSphericalDEMSimulator, public Factorable
{

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Attributes											///
///////////////////////////////////////////////////////////////////////////////////////////////////

	private : shared_ptr<StandAloneSimulator> simulator;
	private : int currentIteration;
	private : int maxIteration;
	private : bool stop;
	private : Chrono chron;
	private : bool record;

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor/Destructor									///
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	/*! Constructor */
	public : QtSphericalDEM (QWidget * parent = 0, const char * name = 0 );

	/*! Destructor */
	public : virtual ~QtSphericalDEM ();

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods											///
///////////////////////////////////////////////////////////////////////////////////////////////////

	public slots : virtual void pbPathClicked();
	public slots : virtual void pbLoadClicked();
	public slots : virtual void pbStartClicked();
	public slots : virtual void pbStopClicked();
	public slots : virtual void bgTimeStepClicked(int i);
	public slots : virtual void pbOutputDirectoryClicked();
	public slots : virtual void cbRecordToggled(bool b) { record = b;};

	protected : void closeEvent(QCloseEvent *evt);

	REGISTER_CLASS_NAME(QtSphericalDEM);
	REGISTER_BASE_CLASS_NAME(Factorable);

};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

REGISTER_FACTORABLE(QtSphericalDEM);
                    
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __QTSPHERICALDEMSIMULATOR_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

