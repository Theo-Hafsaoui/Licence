import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

Im = Image.open('lena.jpeg')
Imarray = np.asarray(Im)

plt.figure()
plt.imshow(Imarray, cmap='gray')

# Calculer et afficher la densité de probabilité de l'image
xe = np.asarray(range(np.amax(Imarray[:])+2))
H1, xe = np.histogram(Imarray.reshape(-1), bins=xe)
P1 = H1/Imarray.size
plt.figure()
plt.plot(P1)
