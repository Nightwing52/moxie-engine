#ifndef CAMERA_H
#define CAMERA_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

enum MODE {
        FREE,
        ORTHO,
};

enum DIRECTION {
        UP,
        DOWN,
        LEFT,
        RIGHT,
};

class Camera {
        public:
                Camera();
                void Reset(void);
                void Update(void);
                void Move(DIRECTION dir);
                void ChangePitch(float degrees);
                void ChangeHeading(float degrees);
                void Move2D(int x, int y);
        private:
                MODE m_mode;
                glm::vec3 m_position;
                glm::vec3 m_target;
                float m_zNear;
                float m_zFar;
                int m_FOV;
};

#endif
