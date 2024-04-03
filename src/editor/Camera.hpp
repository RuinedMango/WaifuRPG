#pragma once

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
class Camera {
private:
    glm::vec3 _position;

    glm::vec3 _moveSpeed = glm::vec3(0.08f);
public:
    glm::vec3 _up;
    enum MovementType {FORWARD, BACKWARD, LEFT, RIGHT, UP, DOWN};

    glm::vec3 _direction;
    Camera(uint32_t width, uint32_t height) {
        _direction = glm::vec3(-2, 0, 0);
        _up = glm::vec3(0.0f, 0.0f, 1.0f);

        _position = glm::vec3(2.0f, 0.0f, 0.0f);
    }

    void rotate(float angle, glm::vec3 axis, float sensitivity) {
        _direction = glm::rotate(_direction, angle * sensitivity, axis);
    }

    void move(MovementType movement) {
        switch(movement) {
            case FORWARD:
                _position += _direction * _moveSpeed;
                break;
            case BACKWARD:
                _position -= _direction * _moveSpeed;
                break;
            case LEFT:
                _position -= glm::normalize(glm::cross(_direction, _up)) * _moveSpeed;
                break;
            case RIGHT:
                _position += glm::normalize(glm::cross(_direction, _up)) * _moveSpeed;
                break;
            case UP:
                _position += _up * _moveSpeed;
                break;
            case DOWN:
                _position -= _up * _moveSpeed;
                break;
        }
    }

    glm::mat4 getMVP() {
        glm::mat4 _view = glm::lookAt(_position, _position + _direction, _up);
        return _view;
    }
};