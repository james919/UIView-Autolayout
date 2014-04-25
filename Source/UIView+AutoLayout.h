//
//  UIView+AutoLayout.h
//
//  Created by Richard Turton on 18/10/2012.

#import <UIKit/UIKit.h>

/** This is the autolayout category.
 
 Blah blah blah.
 */

/**
 *  Options for pinning item edges.
 */
typedef NS_OPTIONS(NSUInteger, JRTViewPinEdges) //TODO: verify that this change is OK.
{
    /**
     *  Pins the top edge of an item.
     */
    JRTViewPinTopEdge = 1 << 0,
    /**
     *  Pins the right edge of an item.
     */
    JRTViewPinRightEdge = 1 << 1,
    /**
     *  Pins the bottom edge of an item.
     */
    JRTViewPinBottomEdge = 1 << 2,
    /**
     *  Pins the left edge of an item.
     */
    JRTViewPinLeftEdge = 1 << 3,
    /**
     *  Pins all edges of an item.
     */
    JRTViewPinAllEdges = ~0UL
};

@interface UIView (AutoLayout)

/**
 @name Initializing a View Object
 */

/**
 *  Returns a frameless view that does not automatically use autoresizing (for use in autolayouts).
 *
 *  @return A frameless view that does not automatically use autoresizing (for use in autolayouts).
 */
+(instancetype)autoLayoutView;

/** @name Pinning to the Superview */

/**
 *  Pins a view to a specific edge(s) of its superview, with a specified inset.
 *
 *  @param edges The edges of the superview the receiver should pin to.
 *  @param inset The amount of space that the receiver should inset itself to within the superview.
 *
 *  @return An array of `NSLayoutConstraint` objects generated by this method.
 */
-(NSArray*)pinToSuperviewEdges:(JRTViewPinEdges)edges inset:(CGFloat)inset;

/**
 *  Pins a view to specific edge(s) of its superview, with a specified inset, using the layout guides of the viewController parameter for top and bottom pinning if appropriate.
 *
 *  @param edges The edges of the superview the receiver should pin to.
 *  @param inset The amount of space that the receiver should inset itself to within the superview.
 *  @param viewController The `UIViewController` with the top and bottom layout guides that should be respected by the method. Setting this value to `nil` will force the constraints to ignore the top and bottom layout guides. If the layout guides do not exist (pre iOS 7) then this method will ignore the layout guides.
 *
 *  @return An array of `NSLayoutConstraint` objects generated by this method.
 */
-(NSArray*)pinToSuperviewEdges:(JRTViewPinEdges)edges inset:(CGFloat)inset usingLayoutGuidesFrom:(UIViewController*)viewController;

/**
 *  Pins a view to all edges of its superview, with specified edge insets
 *
 *  @param insets The amount of space that the receiver should inset itself to within the superview from each edge.
 *
 *  @return An array of `NSLayoutConstraint` objects generated by this method.
 */
-(NSArray*)pinToSuperviewEdgesWithInset:(UIEdgeInsets)insets;

/** @name Misc */

/// Centers the receiver in the specified view
-(NSArray *)centerInView:(UIView*)view;

/// Centers the receiver in the superview
-(NSLayoutConstraint *)centerInContainerOnAxis:(NSLayoutAttribute)axis;

/// Pins an attribute to any valid attribute of the peer item. The item may be the layout guide of a view controller. Provide a constant for offset/inset along with a relation.
-(NSLayoutConstraint *)pinAttribute:(NSLayoutAttribute)attribute toAttribute:(NSLayoutAttribute)toAttribute ofItem:(id)peerItem withConstant:(CGFloat)constant relation:(NSLayoutRelation)relation;

/// Pins an attribute to any valid attribute of the peer item. The item may be the layout guide of a view controller. Provide a constant for offset/inset
-(NSLayoutConstraint *)pinAttribute:(NSLayoutAttribute)attribute toAttribute:(NSLayoutAttribute)toAttribute ofItem:(id)peerItem withConstant:(CGFloat)constant;

/// Pins an attribute to any valid attribute of the peer item. The item may be the layout guide of a view controller
-(NSLayoutConstraint *)pinAttribute:(NSLayoutAttribute)attribute toAttribute:(NSLayoutAttribute)toAttribute ofItem:(id)peerItem;

/// Pins an attribute to the same attribute of the peer item. The item may be the layout guide of a view controller
-(NSLayoutConstraint *)pinAttribute:(NSLayoutAttribute)attribute toSameAttributeOfItem:(id)peerItem;

/// Pins an attribute to the same attribute of the peer item. The item may be the layout guide of a view controller. Provide a constant for offset/inset
-(NSLayoutConstraint *)pinAttribute:(NSLayoutAttribute)attribute toSameAttributeOfItem:(id)peerItem withConstant:(CGFloat)constant;

/// Pins a views edge(s) to another views edge(s). Both views must be in the same view hierarchy.
-(NSArray *)pinEdges:(JRTViewPinEdges)edges toSameEdgesOfView:(UIView *)peerView;
-(NSArray *)pinEdges:(JRTViewPinEdges)edges toSameEdgesOfView:(UIView *)peerView inset:(CGFloat)inset;

/// Set to a specific size. 0 in any axis results in no constraint being applied.
-(NSArray *)constrainToSize:(CGSize)size;

/// Set to a specific width or height.
-(NSLayoutConstraint *)constrainToWidth:(CGFloat)width;
-(NSLayoutConstraint *)constrainToHeight:(CGFloat)height;

// Set minimum and maximum sizes. 0 in any axis results in no constraint in that direction. (e.g. 0 maximumHeight means no max height)
-(NSArray *)constrainToMinimumSize:(CGSize)minimum maximumSize:(CGSize)maximum;

// Set a minimum size. 0 in any axis results in no constraint being applied.
-(NSArray *)constrainToMinimumSize:(CGSize)minimum;

// Set a maximum size. 0 in any axis results in no constraint being applied.
-(NSArray *)constrainToMaximumSize:(CGSize)maximum;

/// Pins a point to a specific point in the superview's frame. Use NSLayoutAttributeNotAnAttribute to only pin in one dimension
-(NSArray*)pinPointAtX:(NSLayoutAttribute)x Y:(NSLayoutAttribute)y toPoint:(CGPoint)point;

/// Spaces the views evenly along the selected axis. Will force the views to the same size to make them fit
-(NSArray*)spaceViews:(NSArray*)views onAxis:(UILayoutConstraintAxis)axis withSpacing:(CGFloat)spacing alignmentOptions:(NSLayoutFormatOptions)options;

/// Spaces the views evenly along the selected axis, using their intrinsic size
-(NSArray*)spaceViews:(NSArray*)views onAxis:(UILayoutConstraintAxis)axis;

@end












/** Deprecated methods are listed here.
 
 All methods listed in this document have been deprecated. The below documentation will provide instructions on how to migrate to the newer more flexible methods.
 
 @warning Deprecated methods will be removed in future releases.
 */

@interface UIView (AutoLayoutDeprecated)

/** @name Pinning Attributes of Views */

/**
 *  Pin an attribute to the same attribute on another view. Both views must be in the same view hierarchy.
 *  @deprecated use pinAttribute:toSameAttributeOfItem: instead
 *
 *  @param attribute The attribute of the receiver that you want to pin to the `peerView`.
 *  @param peerView  The view you want to pin the receiver to.
 *
 *  @return The constraint generated by this method.
 */
-(NSLayoutConstraint *)pinAttribute:(NSLayoutAttribute)attribute toSameAttributeOfView:(UIView *)peerView DEPRECATED_MSG_ATTRIBUTE("use pinAttribute:toSameAttributeOfItem: instead");


/** @name Pinning Edges of Views */


/**
 *  Pins a view's edge to a peer view's edge. Both views must be in the same view hierarchy.
 *  @deprecated use pinAttribute:toAttribute:ofItem: instead
 *
 *  @param edge     The edge of the receiver that you want to pin.
 *  @param toEdge   The edge of the `peerView` that you want to pin
 *  @param peerView The view that you want to pin the receiver to.
 *
 *  @return The constraint generated by this method.
 */
-(NSLayoutConstraint *)pinEdge:(NSLayoutAttribute)edge toEdge:(NSLayoutAttribute)toEdge ofView:(UIView*)peerView DEPRECATED_MSG_ATTRIBUTE("use pinAttribute:toAttribute:ofItem: instead");

/**
 *  Pins a view's edge to a peer view's edge, with an inset. Both views must be in the same view hierarchy.
 *  @deprecated use pinAttribute:toAttribute:ofItem:withConstant: instead
 *
 *  @param edge     The edge of the receiver that you want to pin.
 *  @param toEdge   The edge of the `peerView` that you want to pin
 *  @param peerView The view that you want to pin the receiver to.
 *  @param inset    The inset that you want to apply to the constraint
 *
 *  @return The constraint generated by this method.
 */
-(NSLayoutConstraint *)pinEdge:(NSLayoutAttribute)edge toEdge:(NSLayoutAttribute)toEdge ofView:(UIView *)peerView inset:(CGFloat)inset DEPRECATED_MSG_ATTRIBUTE("use pinAttribute:toAttribute:ofItem:withConstant: instead");

/**
 *  Pins a view's edge to a peer item's edge. The item may be the layout guide of a view controller
 *  @deprecated use pinAttribute:toAttribute:ofItem instead
 *
 *  @param edge     The edge of the receiver that you want to pin.
 *  @param toEdge   The edge of the `peerView` that you want to pin
 *  @param peerItem The view that you want to pin the receiver to.
 *
 *  @return The constraint generated by this method.
 */
-(NSLayoutConstraint *)pinEdge:(NSLayoutAttribute)edge toEdge:(NSLayoutAttribute)toEdge ofItem:(id)peerItem DEPRECATED_MSG_ATTRIBUTE("use pinAttribute:toAttribute:ofItem instead");

/**
 *  Pins a view's edge to a peer item's edge, with an inset. The item may be the layout guide of a view controller
 *  @deprecated use pinAttribute:toAttribute:ofItem:withConstant: instead
 *
 *  @param edge     The edge of the receiver that you want to pin.
 *  @param toEdge   The edge of the `peerView` that you want to pin
 *  @param peerItem The view that you want to pin the receiver to.
 *  @param inset    The inset that you want to apply to the constraint
 *
 *  @return The constraint generated by this method.
 */
-(NSLayoutConstraint *)pinEdge:(NSLayoutAttribute)edge toEdge:(NSLayoutAttribute)toEdge ofItem:(id)peerItem inset:(CGFloat)inset DEPRECATED_MSG_ATTRIBUTE("use pinAttribute:toAttribute:ofItem:withConstant: instead");

/**
 *  Pins a view's edge to a peer item's edge, with an inset and a specific relation. The item may be the layout guide of a view controller.
 *  @deprecated use pinAttribute:toAttribute:ofItem:withConstant:relation: instead
 *
 *  @param edge     The edge of the receiver that you want to pin.
 *  @param toEdge   The edge of the `peerView` that you want to pin
 *  @param peerItem The view that you want to pin the receiver to.
 *  @param inset    The inset that you want to apply to the constraint
 *  @param relation The relation that you wish to apply to the constraint
 *
 *  @return The constraint generated by this method.
 */
-(NSLayoutConstraint *)pinEdge:(NSLayoutAttribute)edge toEdge:(NSLayoutAttribute)toEdge ofItem:(id)peerItem inset:(CGFloat)inset relation:(NSLayoutRelation)relation DEPRECATED_MSG_ATTRIBUTE("use pinAttribute:toAttribute:ofItem:withConstant:relation: instead");

@end
