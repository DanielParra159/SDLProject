#include "Animation.h"

#include <utility>
#include "Texture.h"

Animation::Animation(std::string path, SDL_Renderer *renderer, int frames, float duration, int frameHeight,
                     int frameWidth) : _texture(
        new Texture(std::move(path), renderer)), _frames(frames), _duration(duration), _currentTime(0.0f),
                                       _sourceRect(),
                                       _frameHeight(frameHeight), _frameWidth(frameWidth) {

}

void Animation::Init() {
    _texture->Init();
    _sourceRect.w = _frameWidth;
    _sourceRect.h = _frameHeight;
}

void Animation::Update(double elapsedSeconds) {
    _currentTime += elapsedSeconds;

    if (_currentTime > _duration) {
        _currentTime -= _duration;
    }

    auto frameIndex = int(_currentTime / _duration * 10);

    _sourceRect.x = frameIndex * _frameWidth;
    _texture->SetSourceRect(&_sourceRect);
}

void Animation::Render(const SDL_Rect *destRect) const {
    _texture->Render(destRect);
}

void Animation::Release() {
    _texture->Release();
    delete _texture;
}
