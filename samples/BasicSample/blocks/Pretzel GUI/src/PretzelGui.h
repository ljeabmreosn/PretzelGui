//
//  Header.h
//  BasicSample
//
//  Created by Charlie Whitney on 2/4/14.
//
//

#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"

#include "PretzelGlobal.h"
#include "BasePretzel.h"
#include "PretzelRow.h"

//
#include "PretzelLabel.h"
#include "PretzelSlider.h"
#include "PretzelSaveLoad.h"
#include "PretzelButton.h"
#include "PretzelToggle.h"

class PretzelGui : public PretzelRow {
  public:
    PretzelGui(std::string title="");
	PretzelGui(std::string title, int width, int height);
	PretzelGui(std::string title, PretzelFillStyle width, PretzelFillStyle height);
    
    void draw();
	
	void setSize( ci::Vec2f size ){
		mBounds.x2 = size.x;
		mBounds.y2 = size.y;

		//updateBounds(Vec2f::zero(), mBounds);
		updateChildrenBounds();
	}

	// ------------------
	void addLabel(std::string labelText);
	void addSlider(std::string label, float *variable, float min, float max);
	void addSaveLoad();
	void addToggle( std::string label, bool *value);

	template<typename T, typename Y>
	inline void addButton(std::string labelText, T callback, Y *callbackObject){
		PretzelButton *newButton = new PretzelButton(this, labelText);

		//PretzelButton *newButton = new PretzelButton(this, labelText);
		newButton->signalOnPress.connect(std::bind(callback, callbackObject));
	}

  private:
    void init( std::string title="");

	// mouse events
	boost::signals2::scoped_connection  mMouseBeganCallBack,
										mMouseMovedCallBack,
										mMouseEndCallBack;

	virtual void onMouseDown(ci::app::MouseEvent &event);
	virtual void onMouseDragged(ci::app::MouseEvent &event);
	virtual void onMouseUp(ci::app::MouseEvent &event);

	ci::Vec2i		mPos;

    ci::Surface32f  mSkin;
    ci::gl::Texture mTex;


	PretzelLabel	*defaultLabel;
	bool		bDragging;
	ci::Vec2f	mDragOffset;
};