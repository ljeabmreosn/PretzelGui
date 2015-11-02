//
//  ScrollPane.h
//  BasicSample
//
//  Created by Charlie Whitney on 6/24/14.
//
//

#pragma once

#include "cinder/app/App.h"

#include "components/PretzelRow.h"
#include "components/BasePretzel.h"
#include "modules/PretzelLabel.h"

namespace pretzel {

    class ScrollPane : public PretzelRow {
      public:
        ScrollPane(BasePretzel *base, int width, int height);
        virtual void draw();
        
        virtual void mouseDown(const ci::vec2 &pos);
		virtual void mouseDragged(const ci::vec2 &pos);
		virtual void mouseUp(const ci::vec2 &pos);
		virtual void mouseMoved(const ci::vec2 &pos);
        virtual void mouseWheel(const float increment);
        
      protected:
        void updateChildrenBounds();
        void updateLabelPositions();
        
        float       mScrolledPct;
        ci::vec2    mScrolledHandleAmt;
        ci::vec2    mScrolledFrameAmt;
        
        float       mChildrenHeight;
        float       mBotScrollPadding;
        
        ci::Rectf   mScrollHandle;
        ci::vec2    mStartDragOffset;
        
        bool        bDragging;
        bool        bHover;
        bool        bCanScroll;
    };
}