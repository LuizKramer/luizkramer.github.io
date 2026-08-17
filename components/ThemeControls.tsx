"use client";
import { Menu, Moon, Sun, X } from "lucide-react";
import { useState } from "react";
export function ThemeToggle() {
  function toggle() { const next = document.documentElement.dataset.theme !== "dark"; document.documentElement.dataset.theme = next ? "dark" : "light"; localStorage.setItem("theme", next ? "dark" : "light"); }
  return <button className="icon-button theme-toggle" onClick={toggle} aria-label="Alternar tema"><Sun className="sun-icon" size={18}/><Moon className="moon-icon" size={18}/></button>;
}
export function MobileNav({ links }: { links: readonly { href: string; label: string }[] }) {
  const [open, setOpen] = useState(false);
  return <div className="mobile-nav"><button className="icon-button" onClick={() => setOpen(!open)} aria-expanded={open} aria-controls="mobile-menu" aria-label="Abrir menu">{open ? <X size={20}/> : <Menu size={20}/>}</button>{open && <nav id="mobile-menu" aria-label="Navegação móvel">{links.map(l => <a key={l.href} href={l.href} onClick={() => setOpen(false)}>{l.label}</a>)}</nav>}</div>;
}
