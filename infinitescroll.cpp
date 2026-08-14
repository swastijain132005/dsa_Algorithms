let page = 1;

async function loadData() {

    const res = await fetch(`API_URL?page=${page}`);

    const data = await res.json();

    data.forEach(item => {
        const div = document.createElement("div");

        div.innerText = item.title;

        document.body.appendChild(div);
    });

    page++;
}

window.addEventListener("scroll", () => {

    if (window.innerHeight + window.scrollY >= document.body.offsetHeight - 200) {
        loadData();
    }

});

loadData();
