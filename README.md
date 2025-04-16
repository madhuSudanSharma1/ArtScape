# 🎨 ArtScape: Gallery at Your Space

*A 3D Virtual Art Gallery crafted with the elegance of OpenGL and the power of C++.*

---

## 🖼️ Project Overview

**ArtScape** is a fully immersive 3D virtual art gallery developed using **OpenGL** and its supporting libraries: **GLM**, **GLFW**, **GLAD**, and **STBI**. This project aims to simulate the ambiance of a physical art gallery within a digital environment — enabling intuitive navigation, realistic lighting, and artistic interaction.

> ✨ *Experience art like never before — wherever you are.*

---

## 🎯 Objectives

- 🏛️ Build a realistic and navigable virtual art space.
- 💡 Implement advanced lighting techniques (ambient, diffuse, specular).
- 📷 Integrate a 3D viewing pipeline using camera transformations and projections.
- 🎮 Enable smooth and responsive user interaction via keyboard/mouse input.

---

## 🛠️ Tech Stack

| Component  | Description                              |
|------------|------------------------------------------|
| **C++**    | Core programming language                |
| **OpenGL** | Graphics rendering API                   |
| **GLM**    | Mathematics library for graphics         |
| **GLFW**   | Window/context/input management          |
| **GLAD**   | OpenGL function loader                   |
| **STBI**   | Image loading for texture mapping        |

---

## 🧱 Key Features

- 🧭 **3D Camera System**: Move, pan, and look around the gallery.
- 💡 **Realistic Lighting**: Ambient, diffuse, and specular reflections.
- 🖌️ **Art Display Walls**: Rendered artworks with texture mapping.
- 🧊 **3D Environment**: A full room layout with perspective viewing.
- 🖱️ **Interactive Controls**: WASD for movement, mouse for looking around.

---

## 📐 Core Concepts Applied

### 🔦 Lighting
- Ambient lighting for uniform illumination.
- Diffuse lighting for depth and realism.
- Specular highlights for shiny surfaces.

### 🧭 3D Viewing Pipeline
- Model → View → Projection → Clipping → Rasterization
- Vertex & Fragment shading for effects and realism.

### 📸 Camera System
- Adjustable position, direction, and perspective.
- Field of View (FoV) & projection matrix control.

---

## 🧭 Navigation Controls

| Action           | Control           |
|------------------|-------------------|
| Move Forward     | `W`               |
| Move Backward    | `S`               |
| Strafe Left      | `A`               |
| Strafe Right     | `D`               |
| Look Around      | Mouse movement    |
| Exit             | `Esc`             |

---

## 🖼️ Gallery Previews

> *(Screenshots from the virtual gallery environment)*

  ![image](https://github.com/user-attachments/assets/e067ed40-086d-47da-8994-9d3e95b0fb4b)
  ![image](https://github.com/user-attachments/assets/005184d7-66e0-43ec-b944-bcbada0c6ce3)
  ![image](https://github.com/user-attachments/assets/37d7e82c-b028-4648-a752-8d2540d37ce1)
  ![image](https://github.com/user-attachments/assets/4f89f9fc-408b-4064-b36d-059a87093a15)
  ![image](https://github.com/user-attachments/assets/75ddafd6-f670-4e3a-a5a7-5ad2f4c2f50e)
  ![image](https://github.com/user-attachments/assets/c98310ba-d601-476a-bd1e-956eb44e7397)


---

## 📚 Educational Value

This project acts as an educational bridge:
- 🖼️ For artists — a digital canvas.
- 💻 For developers — an advanced OpenGL example.
- 🧠 For learners — insights into graphics pipelines, shaders, and real-time rendering.

---

## 📦 Project Structure

```
├── /src
│   ├── main.cpp
│   ├── shaders/
│   ├── textures/
├── /resources
│   ├── images/
│   └── art_pieces/
├── README.md
└── ...
```

---

## 🚀 How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/artscape-gallery.git
   cd artscape-gallery
   ```

2. Ensure you have OpenGL, GLFW, GLAD, and GLM installed.

3. Compile and run:
   ```bash
   g++ src/main.cpp -o gallery -lglfw -lGL -ldl -lX11 -lpthread -lXrandr -lXi
   ./gallery
   ```

---

## 🧠 Credits

👩 Madhu Sharma  
🎓 Tribhuvan University, Pulchowk Campus  
📘 Department of Electronics and Computer Engineering

---

## 📌 License

This project is for academic and educational purposes only.

---

> *"Blending art with technology — ArtScape lets you walk through the imagination."*
