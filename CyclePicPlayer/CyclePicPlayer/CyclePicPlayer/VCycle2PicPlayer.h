//
//  VCyclePicPlayer.h
//  VCyclePicPlayer
//
//  Created by Vols on 15/3/18.
//  Copyright (c) 2015年 Vols. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol VCyclePicPlayerDelegate;

@interface VCycle2PicPlayer : UIView<UIScrollViewDelegate> {
    UIScrollView    * _scrollView;
    UIPageControl   * _pageControl;
    
    NSInteger       _totalPages;
    NSInteger       _curPage;
    
    NSMutableArray  * _curViews;
}


@property (nonatomic, readonly)  UIScrollView    * scrollView;
@property (nonatomic, readonly)  UIPageControl   * pageControl;
//@property (nonatomic, strong) TAPageControl   * pageControl;
@property (nonatomic, assign)    BOOL            isAutoPlay;

@property (nonatomic, assign)    NSInteger       currentPage;

@property (nonatomic, assign, setter = setDelegate:) id<VCyclePicPlayerDelegate> delegate;


@property (nonatomic, assign) CGSize    pageControlDotSize; // 分页控件小圆标大小
@property (nonatomic, strong) UIColor   * dotColor;         // 分页控件小圆标颜色

//初始化数据
- (void)reloadData;

- (void)setViewContent:(UIView *)view atIndex:(NSInteger)index;


- (void)stopPlay;
- (void)startPlay;

@end


@protocol VCyclePicPlayerDelegate <NSObject>

@optional

- (NSInteger)numberOfPages;
- (UIView *)cyclePicPlayer:(VCycle2PicPlayer *)cyclePicPlayer pageAtIndex:(NSInteger)index;

- (void)cyclePicPlayer:(VCycle2PicPlayer *)cyclePicPlayer atIndex:(NSInteger)index;
@end





