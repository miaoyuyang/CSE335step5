/**
 * \file Actor.h
 *
 * \author Yiteng Zhang
 *
 * Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */
#pragma once

#include "Drawable.h"
#include <string>
#include <memory>
#include <vector>

class CPicture;

/**An actor is some graphical object that consists of
 * one or more parts.Actors can be animated.
 */
class CActor
{
public:
    /** constructor 
    * \param name The name of the actor*/
    CActor(const std::wstring& name);

    /** Default constructor disabled */
    CActor() = delete;
    /** Copy constructor disabled */
    CActor(const CActor&) = delete;
    /** Assignment operator disabled */
    void operator=(const CActor&) = delete;

    virtual ~CActor();

    void SetRoot(std::shared_ptr<CDrawable> root);
    void Draw(Gdiplus::Graphics* graphics);
    std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);
    void AddDrawable(std::shared_ptr<CDrawable> drawable);

    /** Get the actor name
     * \returns Actor name */
    std::wstring GetName() const { return mName; }

    /** The actor position
    * \returns The actor position as a point */
    Gdiplus::Point GetPosition() const { return mPosition; }

    //Gdiplus::Graphics GetPicture() { return mPicture; }

    /** The actor position
    * \param pos The new actor position */
    void SetPosition(Gdiplus::Point pos) { mPosition = pos; }


    /** Actor is enabled
    * \returns enabled status */
    bool IsEnabled() const { return mEnabled; }

    /** Set Actor Enabled
    * \param enabled New enabled status */
    void SetEnabled(bool enabled) { mEnabled = enabled; }

    /** Actor is clickable
    * \returns true if actor is clickable */
    bool IsClickable() const { return mClickable; }

    /** Actor clickable
    * \param clickable New clickable status */
    void SetClickable(bool clickable) { mClickable = clickable; }

    /** Get the picture
    * \returns The picture */
    CPicture* GetPicture() { return mPicture; }

    /** Set Actor image
    * \param picture The image */
    void SetPicture(CPicture* picture) { mPicture = picture; }


private:
    /// The name of actor
    std::wstring mName;
    /// The position of the actor's as a point
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
    /// The states of enabled or not
    bool mEnabled = true;
    /// The states of clickable or not
    bool mClickable = true;

    /// The root drawable
    std::shared_ptr<CDrawable> mRoot;

    /// The drawables in drawing order
    std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;

    /// The picture of the actor
    CPicture* mPicture = nullptr;
};

