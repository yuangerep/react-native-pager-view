/**
 * MIT License
 *
 * Copyright (C) 2024 Huawei Device Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "RNOH/arkui/ArkUINode.h"
#include "generated/react/renderer/components/react_native_pager_view/EventEmitters.h"

namespace rnoh {

    class SwiperNodeDelegate {
    public:
        virtual ~SwiperNodeDelegate() = default;
    
        virtual void onPageSelected(double pageIndex){};
    
        virtual void onPageScroll(facebook::react::RNCViewPagerEventEmitter::OnPageScroll pageScroll){};
    
        virtual void onPageScrollStateChanged(facebook::react::RNCViewPagerEventEmitter::OnPageScrollStateChanged value){};
    
        virtual bool getScrollEnabled(){
          return true;
        };
    
        virtual bool getNativeLock(){
          return false;
        };
    
        virtual void setKeyboardDismiss(){};
    
        
        virtual void setGestureStatus(bool gestureStatus){};

        virtual void setClickTap(bool clickTap) {};
    
        virtual bool getClickTap() { return false; };
    
        virtual void sendEventAnimationsPageScroll(facebook::react::RNCViewPagerEventEmitter::OnPageScroll pageScroll){};
    
        virtual void onSwiperAppear(){};
    };

    class SwiperNode : public ArkUINode {
    protected:
        SwiperNodeDelegate *m_swiperNodeDelegate;
        ArkUI_NodeHandle m_stackArkUINodeHandle;
        double m_targetIndex = 0;
        double m_offset = 0;
        double m_currentIndex = 0;
        bool m_crossoverJump = false;
        int m_offsetCount = 0;
        double m_offsetIndex = 0;
        double m_offsetCountIndex = 0;
        const int OFFSET_DEFAULT_VALUE = 3;
        double m_preOffset = OFFSET_DEFAULT_VALUE;
        bool m_firstSwipe = true;
        bool m_gestureSwipe = false;
        bool m_pageSelectNotify = false;
        std::chrono::high_resolution_clock::time_point animationStart;
        std::chrono::high_resolution_clock::time_point animationEnd;
        bool m_interceptSendOffset = false;
        std::map<void*,ArkUI_NodeHandle> m_nodeHandleMap;
    public:
        SwiperNode();
    
        ~SwiperNode() override;
    
        void setSwiperNodeDelegate(SwiperNodeDelegate *swiperNodeDelegate);

        void insertChild(ArkUINode &child, std::size_t index);

        void removeChild(ArkUINode &child);

        void onNodeEvent(ArkUI_NodeEventType eventType, EventArgs& eventArgs) override;

        SwiperNode &setIndex(int const &initialPage);

        SwiperNode &setIndexNoAnimation(int const &initialPage);
    
        SwiperNode &setVertical(std::string const &orientation);
    
        SwiperNode &setDirection(std::string const &layoutDirection);
    
        SwiperNode &setItemSpace(float const &pageMargin);
    
        SwiperNode &setCachedCount(int const &offscreenPageLimit);
    
        SwiperNode &setDisableSwipe(bool const &disableSwipe);
    
        SwiperNode &setEffectMode(std::string const &effectMode);
    
        SwiperNode &setLoop(bool const &loop);
    
        SwiperNode &setDuration(float const &duration);
    
        SwiperNode &setIndicator(bool const &indicator);
    
        SwiperNode &setCurve(int const &curve);
    
    };

} // namespace rnoh